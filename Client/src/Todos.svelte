<script lang="ts">
    import Todoitem from "./TodoItem.svelte";
    export let todoList: {id: number, text: string, isComplete: boolean}[];
    export let deleteTodo: (id: number) => void;
</script>

<div class="container">
    {#each todoList as todo}
        <Todoitem {todo} {deleteTodo}/>
    {/each}
</div>

<style>
    .container {
        margin-top: 10px;
    }
</style>