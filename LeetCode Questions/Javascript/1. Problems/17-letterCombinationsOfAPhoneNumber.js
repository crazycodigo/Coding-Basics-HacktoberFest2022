var letterCombinations = function(digits) {
    let combinations = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    };
    
    if (!digits)
        return []
    
    let current = [];
    let result = [];
    recursion(0, digits, current, result, combinations);
    return result;
    
};

function recursion(index, digits, current, result, combinations) {
    if (index >= digits.length) {
        result.push([...current].join(""));
        return;
    }
        
    
    let digit = digits[index];
    for (let letter of combinations[digit]) {
        current.push(letter);
        recursion(index + 1, digits, current, result, combinations);
        current.pop();
    }
    
}