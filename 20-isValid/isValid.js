var isValid = function(s) {
    const map = new Map([["(", ")"], ["{", "}"], ["[", "]"]]);
    const stack = [];
    for (const v of s) {
        const l = stack.length;
        if (!l) stack.push(v);
        else {
            if (map.get(stack[l - 1]) === v) stack.pop();
            else stack.push(v);
        }
    }
    return stack.length === 0;
};
