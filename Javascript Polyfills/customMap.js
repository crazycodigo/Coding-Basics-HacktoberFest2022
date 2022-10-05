// polyfill for map() method

Array.prototype.customMap = function(callback) {
    let arr = this;
    let result = [];
    for (let i = 0; i < arr.length; i ++) {
        result.push(callback(arr[i], i, arr));
    }
    return result;
}

// usage

let array = [1,2,3,4,5];
let twiceOfEachNumber = array.customMap((num) => {
    return num * 2;
});
console.log(twiceOfEachNumber); // [2, 4, 6, 8, 10]