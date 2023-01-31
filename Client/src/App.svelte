<script lang="ts">
	import Input from "./Input.svelte";
	import Todos from "./Todos.svelte";

	type todoType = {id: number, text: string, completed: boolean};

	let todoInput: string = "";
	let todoList: todoType[] = [
		{
			id: 1,
			text: "My first Todo",
			completed: false
		}
	];

	let lastId: number = todoList[todoList.length - 1].id;

	let addTodo: () => void = () => {
		if (todoInput) {
			let newTodo: todoType = {
				id: ++lastId,
				text: todoInput,
				completed: false
			}

			todoList[todoList.length] = newTodo;
			todoInput = "";
		}
	};

	let handleKeyUp: (e: any) => void = e => {
		todoInput = e.target.value;
		if (e.keyCode === 13) {
			addTodo();
		}
	}
</script>

<main>
	<div>
		<p>Todo List</p>
		<Input {todoInput} {addTodo} {handleKeyUp} />
		<Todos todoList={todoList}/>
	</div>
</main>

<style>
	main {
		text-align: center;
		max-width: 500px;
		padding: 1em;
		margin: 0 auto;
	}

	p {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}
</style>