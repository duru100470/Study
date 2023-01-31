<script lang="ts">
    import Todoitem from "./TodoItem.svelte";
    export let todoList: {id: number, text: string, completed: boolean}[];
</script>

<div class="container">
    {#each todoList as todo}
        <Todoitem {todo}/>
    {/each}
</div>

<style>
    .container {
        margin-top: 10px;
    }
</style>