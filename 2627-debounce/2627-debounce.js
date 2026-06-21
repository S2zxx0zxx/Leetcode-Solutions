var debounce = function(fn, t) {
    let timer = null;
    
    return function(...args) {
        clearTimeout(timer);
        timer = setTimeout(() => {
            fn(...args);
        }, t);
    };
};