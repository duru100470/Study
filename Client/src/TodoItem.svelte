<script lang="ts">
    export let todo: {id: number, text: string, isComplete: boolean};
    export let completeTodo: (id: number) => void;
    export let deleteTodo: (id: number) => void;
</script>

<div class="wrapper">
    <input type="checkbox" checked={todo.isComplete} on:click={() => completeTodo(todo.id)} />
    <p>{todo.text}</p>
    <button on:click={() => deleteTodo(todo.id)}>❌</button>
</div>

<style>
    .wrapper {
        display: grid;
        grid-template-columns: 1fr 10fr 1fr;
        max-width: 500px;
        border-radius: 5px;
        background: #e9e9e9;
        margin-bottom: 5px;
    }

    input {
        margin: auto;
        margin-left: 8px;
        width: 30px;
        height: 30px;
    }

    button {
        margin: auto;
        margin-right: 8px;
        width: 30px;
        height: 30px;
        padding: 0px;
        text-align: center;
    }
</style>