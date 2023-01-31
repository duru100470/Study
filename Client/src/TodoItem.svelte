<script lang="ts">
    export let todo: {id: number, text: string, completed: boolean};
    export let deleteTodo: (id: number) => void;
</script>

<div class="wrapper">
    <input type="checkbox" />
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
        width: 30px;
        height: 30px;
    }

    button {
        margin: auto;
        width: 30px;
        height: 30px;
        padding: 0px;
        text-align: center;
    }
</style>