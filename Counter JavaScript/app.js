// selecting all the buttons
const increaseBtn = document.querySelector("#increase-btn")
const resetBtn = document.querySelector("#reset-btn")
const decreaseBtn = document.querySelector("#decrease-btn")

// selecting output
const outputMsg = document.querySelector("#output")

//giving the initial count as 0
let initialValue = 0;

// increase the value
increaseBtn.addEventListener("click",function(){
  initialValue++
  outputMsg.innerText = initialValue
})

// reset the value
resetBtn.addEventListener("click",function(){
  initialValue = 0
  outputMsg.innerText = initialValue
})

// decrease the value
decreaseBtn.addEventListener("click",function(){
  initialValue--
  outputMsg.innerText = initialValue
})