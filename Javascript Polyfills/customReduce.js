// polyfill for reduce() method

Array.prototype.customReduce = function(fn, initialValue = null) {
    let array = this;
    let index = initialValue ? 0 : 1;
    let accumulator = initialValue ? initialValue : array[0];
    for (let i = index; i < array.length; i ++) {
        accumulator = fn(accumulator, array[i]);
    }
    return accumulator;
}

// usage

let array = [1,2,3,4,5];
let sum = array.customReduce((acc, num) => {
    return acc + num;
});
console.log(sum); // 15
