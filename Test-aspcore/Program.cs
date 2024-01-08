using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddDbContext<TodoDb>(opt => 
    opt.UseSqlite(builder.Configuration.GetConnectionString("TodoContext")));
builder.Services.AddDatabaseDeveloperPageExceptionFilter();

var app = builder.Build();
app.UseStaticFiles();

app.MapGroup("/todos")
    .MapTodosApi()
    .WithTags("Todo Endpoints");

app.MapGet("/", async req => {
    await req.Response.SendFileAsync("./Pages/index.html");
});

app.Run();
