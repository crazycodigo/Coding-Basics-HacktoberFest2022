To make my Vanilla JS strong I made this app that uses DOM elements.

 It's very easy to build.

 Let's Begin!!!

### What are we going to make?

- A counter which is going to have 3 buttons.
- Input: the user clicks on a button.
- Processing: according to the button clicked we increment, decrement, or reset the value.
- Output: we show the user by updating the value in real-time.

## Final Output

![gif](https://user-images.githubusercontent.com/53895282/193577345-bdbc3e54-68ea-41a0-9e59-27b4d8b4f10f.gif)

## Step 1 : HTML

![html](https://user-images.githubusercontent.com/53895282/193577461-7519c3b8-67f7-4d43-9053-68bcf185f601.png)

- A div for showing the output which is initially 0.
- 3 buttons with their respective ids.
- Increase button to increment.
- Reset button to make it 0.
- Decrease button to decrement.

## Step 2 : JavaScript

![selecting](https://user-images.githubusercontent.com/53895282/193577526-fc3862fa-44d2-4f28-86ea-4ec4b6884b2e.png)

- First, we select the buttons with their respective ids using document.querySelector and assign them to variables.
- document.querySelector returns the respective CSS selector that matches it.

![output](https://user-images.githubusercontent.com/53895282/193577561-ef572f16-964a-451d-bc3f-c2bd5328d040.png)


- Again we use document.querySelector to select the output which displays our counter and assign it to a variable.

![count](https://user-images.githubusercontent.com/53895282/193577627-bc096984-9d80-4d38-8e05-f36c2439681c.png)


- Initially, our counter has to be 0.
- We set the initial value to 0.

![processing part](https://user-images.githubusercontent.com/53895282/193577649-45603c16-0090-421c-b8bf-a016ec2dd836.png)


#### Logic/Processing

- We use addEventListener to the variables assigned to the buttons.
- A click event is used so whenever the button is clicked a function is called.
- So, now whenever we click the button the intitalValue increases by 1 .

#### Output

- To display the count we set outputMsg.innerText to be initialValue which keeps getting changed whenever we click a button.

## Step 3 : Adding CSS

- Give it your own styling 😉.

If you learned something new today why not connect with me?

[Twitter](https://twitter.com/zabih01) 

[Github](https://github.com/zabihhaqqani )

[Linkedin](https://www.linkedin.com/in/zabih-haqqani-7ab187191/)
