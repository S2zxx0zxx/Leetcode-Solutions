var sortBy = function(arr, fn) {
    return arr.slice().sort((a, b) => fn(a) - fn(b));
};