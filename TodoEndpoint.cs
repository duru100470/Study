using Microsoft.EntityFrameworkCore;

public static class TodoEndpoints
{
    public static RouteGroupBuilder MapTodosApi(this RouteGroupBuilder group)
    {
        group.MapGet("/", GetAllTodos);
        group.MapGet("/complete", GetAllCompletedTodos);
        group.MapGet("/{id}", GetTodo);
        group.MapPost("/", CreateTodo);
        group.MapPut("/{id}", UpdateTodo);
        group.MapDelete("/{id}", DeleteTodo);

        return group;
    }

    public static async Task<IResult> GetAllTodos(TodoDb db)
    {
        var todos = await db.Todos.ToListAsync();
        return TypedResults.Ok(todos);
    }

    public static async Task<IResult> GetAllCompletedTodos(TodoDb db)
    {
        var todos = await db.Todos.Where(t => t.IsComplete).ToListAsync();
        return TypedResults.Ok(todos);
    }

    public static async Task<IResult> GetTodo(int id, TodoDb db)
    {
        var todo = await db.Todos.FindAsync(id);

        if (todo != null)
        {
            return TypedResults.Ok(todo);
        }
        else
        {
            return TypedResults.NotFound();
        }
    }

    public static async Task<IResult> CreateTodo(Todo todo, TodoDb db)
    {
        var newTodo = new Todo
        {
            Name = todo.Name,
            IsComplete = false
        };
        await db.Todos.AddAsync(newTodo);
        await db.SaveChangesAsync();

        return TypedResults.Created($"/todoitems/{todo.Id}", todo);
    }

    public static async Task<IResult> UpdateTodo(int id, Todo inputTodo, TodoDb db)
    {
        var todo = await db.Todos.FindAsync(id);

        if (todo is null) return TypedResults.NotFound();

        todo.Name = inputTodo.Name;
        todo.IsComplete = inputTodo.IsComplete;

        await db.SaveChangesAsync();

        return TypedResults.Created($"/todoitems/{todo.Id}", todo);
    }

    public static async Task<IResult> DeleteTodo(int id, TodoDb db)
    {
        if (await db.Todos.FindAsync(id) is Todo todo)
        {
            db.Todos.Remove(todo);
            await db.SaveChangesAsync();
            return TypedResults.Ok(todo);
        }

        return TypedResults.NotFound();
    }
}