// Define UI Vars
const form = document.querySelector("#task-form");
const taskList = document.querySelector(".collection");
const clearBtn = document.querySelector(".clear-tasks");
const filter = document.querySelector("#filter");
const taskInput = document.querySelector("#task");

// Load all event listener
loadEventListeners();

function loadEventListeners(){
    // DOM load elements
    document.addEventListener("DOMContentLoaded", getTasks);
    // Add task event
    form.addEventListener("submit", addTask);
    // Remove task
    taskList.addEventListener("click", removeTask);
    // Clear tasks
    clearBtn.addEventListener("click", clearTasks);
    // Filter tasks
    filter.addEventListener("keyup", filterTasks);
}

// Get tasks from LS
function getTasks() {
    let tasks;
    if(localStorage.getItem("tasks") === null) {
        tasks = [];
    } else {
        tasks = JSON.parse(localStorage.getItem("tasks"));
    }
    tasks.forEach(
        function(task){
            const li = document.createElement("li");
            li.className = "collection-item";
            li.appendChild(document.createTextNode(task));
            const link = document.createElement("a");
            link.className  = "delete-item secondary-content";
            link.innerHTML = "<i class='fa fa-times'></i>";
            li.appendChild(link);
            taskList.appendChild(li);
        }
    )
}

// Add Task
function addTask(e) {
    if(taskInput.value === ""){
        alert("Add task");
    }

    // Create li element
    const li = document.createElement("li");
    li.className = "collection-item";
    li.appendChild(document.createTextNode(taskInput.value));
    // Create link
    const link = document.createElement("a");
    link.className  = "delete-item secondary-content";
    link.innerHTML = "<i class='fa fa-times'></i>";
    li.appendChild(link);
    taskList.appendChild(li);
    storeTaskToLocalStorage(taskInput.value);
    taskInput.value = "";
    e.preventDefault();
}

// Store task to local storage
function storeTaskToLocalStorage(task){
    let tasks;
    if(localStorage.getItem("tasks") === null) {
        tasks = [];
    } else {
        tasks = JSON.parse(localStorage.getItem("tasks"));
    }
    tasks.push(task);
    localStorage.setItem("tasks", JSON.stringify(tasks));
}

// Remove task
function removeTask(e){
    if(e.target.parentElement.classList.contains("delete-item")) {
        if(confirm("Are you sure?")) {
        e.target.parentElement.parentElement.remove();
        removeTaskFromLS(e.target.parentElement.parentElement);
        }
    }
}

// Remove from LS
function removeTaskFromLS(taskItem){
    let tasks;
    if(localStorage.getItem("tasks") === null) {
        tasks = [];
    } else {
        tasks = JSON.parse(localStorage.getItem("tasks"));
    }
    tasks.forEach(function(task, index){
        if(taskItem.textContent === task){
            tasks.splice(index, 1);
        }
    });
    localStorage.setItem("tasks", JSON.stringify(tasks));
}

// Clear tasks
function clearTasks(){
    while(taskList.firstChild){
    taskList.removeChild(taskList.firstChild);
    // Clear local storage
    localStorage.clear();
    }
}

// Filter tasks
function filterTasks(e){
    const text = e.target.value;
    document.querySelectorAll(".collection-item").forEach
    (function(task) {
        const item = task.firstChild.textContent;
        if(item.toLowerCase().indexOf(text) != -1) {
            task.style.display = "block";
        } else {
            task.style.display = "none";
        }
    });
}