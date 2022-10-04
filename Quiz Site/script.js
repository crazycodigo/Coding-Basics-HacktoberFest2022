const start_btn = document.querySelector(".start_btn");
const info_box = document.querySelector(".info_box");
const exit_btn = info_box.querySelector(".buttons .quit");
const continue_btn = info_box.querySelector(".buttons .restart");
const quiz_box = document.querySelector(".quiz_box");
const result_box = document.querySelector(".result_box");
const option_list = document.querySelector(".option_list");
const time_line = document.querySelector("header .time_line");
const timeText = document.querySelector(".timer .time_left_txt");
const timeCount = document.querySelector(".timer .timer_sec");
const que_box = document.querySelector(".que_text");
let tickIconTag = '<div class="icon tick"><i class="fas fa-check"></i></div>';
let crossIconTag = '<div class="icon cross"><i class="fas fa-times"></i></div>';
const next_btn = document.querySelector("footer .next_btn");
const quit = document.querySelector("#quit_btn");
var question_number = 0;
let userScore = 0;
let time;
let timer;
let timer_started = false;
start_btn.onclick = () => {
    info_box.classList.add("activeInfo"); //show info box
}
exit_btn.onclick = () => {
    info_box.classList.remove("activeInfo"); //hide info box
}
continue_btn.onclick = () => {
    info_box.classList.remove("activeInfo");
    quiz_box.classList.add("activeQuiz");
    get_questions();

}
const get_questions = async () => {
    try {
        const response = await fetch(`https://opentdb.com/api.php?amount=13&category=29&difficulty=medium`)
        const data = await response.json();
        Show_questions(data);
    } catch (error) {
        console.log(error);
    }
}
function Show_questions(Data) {
    question_number++;
    console.log(Data);
    console.log(Data.results[question_number].question);
    que_box.innerHTML = Data.results[question_number].question;
    const correct_option = random_number(Data.results[question_number].incorrect_answers.length);
    option_list.innerHTML = "";
    next_btn.classList.remove("show");
    let j = 0;
    for (let i = 0; i < Data.results[question_number].incorrect_answers.length + 1; i++) {
        if (i + 1 == correct_option) {
            option_list.innerHTML += `<div class="option"><span>${Data.results[question_number].correct_answer}</span></div>`;
        }
        else {
            option_list.innerHTML += `<div class="option"><span>${Data.results[question_number].incorrect_answers[j]}</span></div>`
            j++;
        }
    }
    if (timer_started) {
        clear_previous_timer();
    }
    time = 16
    set_timer(Data);
    timer_started = true;
    add_click_on_options(Data);
}
function random_number(number_of_incorrect_ans) {
    let number = Math.floor(Math.random() * (number_of_incorrect_ans)) + 1;
    return number;
}
function clear_previous_timer() {
    clearInterval(timer);
}
function set_timer(Data) {
    timer = setInterval(() => {
        time--;
        if (time < 10) {
            timeCount.innerHTML = "0" + time;

        }
        else {
            timeCount.innerHTML = time;
        }
        if (time <= 0) {
            clearInterval(timer);
            question_number++;
            next_que_info(Data);
        }
    }, 1000)
}
function add_click_on_options(Data) {
    const options = document.querySelectorAll('.option');
    options.forEach(option => {
        option.addEventListener("click", () => {
            optionSelected(option, Data);
        }
        );
    });
}
function optionSelected(option, Data) {
    clear_previous_timer();
    const span = option.querySelector('span');
    if (span.innerHTML == Data.results[question_number].correct_answer) {
        userScore++;
        option.classList.add("correct");
        option.insertAdjacentHTML("beforeend", tickIconTag);
        const options = document.querySelectorAll('.option');
        options.forEach(given_option => {
            if (given_option != option) {
                given_option.classList.add("incorrect");
                given_option.insertAdjacentHTML("beforeend", crossIconTag);
                given_option.classList.add("disabled");
            }
        })
    }
    else {
        const options = document.querySelectorAll('.option');
        options.forEach(given_options => {
            given_options.classList.add("disabled");
            const given_options_span = given_options.querySelector('span');
            if (given_options_span.innerHTML == Data.results[question_number].correct_answer) {
                given_options.classList.add("correct");
                given_options.insertAdjacentHTML("beforeend", tickIconTag);
            }
            else {
                given_options.classList.add("incorrect");
                given_options.insertAdjacentHTML("beforeend", crossIconTag);
            }
        });
    }


    next_btn.classList.add("show");
    next_btn.addEventListener("click", () => {
        next_que_info(Data);
    });
}
function next_que_info(Data) {
    if (question_number === 11) {
        show_Result();
    }
    else {
        Show_questions(Data);
    }
}
function show_Result() {
    info_box.classList.remove("activeInfo");
    quiz_box.classList.remove("activeQuiz");
    result_box.classList.add("activeResult");
    const scoreText = result_box.querySelector(".score_text");
    if (userScore > 3) {
        let scoreTag = '<span>and congrats! , You got <p>' + userScore + '</p> out of <p>' + 5 + '</p></span>';
        scoreText.innerHTML = scoreTag;
    }
    else if (userScore > 1) {
        let scoreTag = '<span>and nice , You got <p>' + userScore + '</p> out of <p>' + 5 + '</p></span>';
        scoreText.innerHTML = scoreTag;
    }
    else {
        let scoreTag = '<span>and sorry , You got only <p>' + userScore + '</p> out of <p>' + 5 + '</p></span>';
        scoreText.innerHTML = scoreTag;
    }
    quit.onclick = () => { location.reload() };
}