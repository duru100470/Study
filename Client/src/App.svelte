<script lang="ts">
	import Input from "./Input.svelte";
	import Todos from "./Todos.svelte";
	import {fetchGet, fetchPut, fetchPost, fetchDelete} from "./functions";

	type todoType = {id: number, text: string, isComplete: boolean};

	let todoInput: string = "";
	let todoList: todoType[] = null;

	let lastId: number = todoList[todoList.length - 1].id;

	let addTodo: () => void = () => {
		if (todoInput) {
			let newTodo: todoType = {
				id: ++lastId,
				text: todoInput,
				isComplete: false
			}
		}
	};

	let deleteTodo: (id: number) => void = (id) => {
		todoList = todoList.filter((todo) => todo.id !== id);
	}

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
		<Todos {todoList} {deleteTodo} />
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