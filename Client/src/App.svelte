<script lang="ts">
	import Input from "./Input.svelte";
	import Todos from "./Todos.svelte";
	import {fetchGet, fetchPut, fetchPost, fetchDelete} from "./functions";
	import TodoItem from "./TodoItem.svelte";

	type todoType = {id: number, text: string, isComplete: boolean};

	let todoInput: string = "";
	let todoList: todoType[] = [];

	async function loadTodo(): Promise<void> {
		let res: Response = await fetchGet("/todos");
		todoList = await res.json();
	}

	let addTodo: () => void = () => {
		if (todoInput) {
			let newTodo: todoType = {
				id: 0,
				text: todoInput,
				isComplete: false
			}

			fetchPost("/todos/", newTodo)
				.then(() => todoInput = "")
				.then(() => loadTodo());
		}
	};

	let deleteTodo: (id: number) => void = (id) => {
		fetchDelete(`/todos/${id}`)
			.then(() => loadTodo());
	}

	let completeTodo: (id: number) => void = (id) => {
		let index: number = todoList.findIndex(todo => todo.id === id);

		let newTodo: todoType = {
			...todoList[index]
		}
		newTodo.isComplete = !newTodo.isComplete;

		console.log(newTodo);

		fetchPut(`/todos/${id}`, newTodo)
			.then(() => todoList[index] = newTodo);
	}

	let handleKeyUp: (e: any) => void = e => {
		todoInput = e.target.value;
		if (e.keyCode === 13) {
			addTodo();
		}
	}

	loadTodo();
</script>

<main>
	<div>
		<p>Todo List</p>
		<Input {todoInput} {addTodo} {handleKeyUp} />
		<Todos {todoList} {completeTodo} {deleteTodo} />
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