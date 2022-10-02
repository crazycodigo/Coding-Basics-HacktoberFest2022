// polyfill for filter() method

Array.prototype.customFilter = function(callback) {
    let arr = this;
    let result = [];
    for (let i = 0; i < arr.length; i ++) {
        if(callback(arr[i])) result.push(arr[i]);
    }
    return result;
}

// usage

let array = [1,2,3,4,5];
let evenNumbers = array.customFilter((num) => {
    return num % 2 == 0;
});
console.log(evenNumbers); // [2, 4]