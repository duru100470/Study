<script lang="ts">
    export let todoInput: string;
    export let addTodo: () => void;
    export let handleKeyUp: (e: any) => void;
</script>

<div>
    <input type="text" placeholder="Enter your todo name.." bind:value={todoInput} on:keyup={e => handleKeyUp(e)} />
    <button on:click={addTodo}>Add</button>
</div>