// Function to start the clock when the page loads
window.onload = function(){  
    startClock();
}

// Get the element with id="time"
let time = document.getElementById('time');

// getting the today's date
let currentData = new Date(); 

// assigning the date, day, month and year to the variables
let date = currentData.getDate();
let day = currentData.getDay();
let month = currentData.getMonth();
let year = currentData.getFullYear();

// Array of days to display the day of the week according to the number
let days = ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday'];

day = days[day];

// Main function to start the clock
function startClock(){
    
    let currentData = new Date();
    let seconds = currentData.getSeconds();
    let minutes = currentData.getMinutes();
    let hours = currentData.getHours();
    

    // Conditions to check AM or PM 
    let AMorPM;
    if(hours>=12){
        AMorPM = "PM";
    }
    else{
        AMorPM = "AM";
    }

    let h = hours;
    if(hours==0){
        h = 12;
    }
    // if the hours are greater than 12 then subtract 12 to get the 12 hour format
    else if(hours>12){
        h = hours-12;
    }

    let s = check(seconds);
    let m = check(minutes);
    function check(val){
        if(val<10){
            return '0' + val;
        }
        return val;
    }

    // Displaying the time in the element with id="time"
    time.innerText = h + ':' + m + ':' + s + ' '+AMorPM;
}

// Writing the date in the "date" element
document.getElementById('date').innerText = date+'/ '+month+'/ '+year;
document.getElementById('day').innerText = day;

// Calling the function every second
setInterval(startClock,1000);
