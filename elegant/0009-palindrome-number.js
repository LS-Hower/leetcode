function isPalindrome(x) {
    return (s => s == [...s].reverse().join(''))(x.toString())
};
