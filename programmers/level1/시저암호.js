function solution(s, n) {
    return s.split("").map(a => {
        if(a === " ") return " ";
        
        let tmp = String.fromCharCode(a.toUpperCase().charCodeAt(0) + n);
        if(tmp > 'Z') tmp = String.fromCharCode(tmp.charCodeAt(0) - 26);
        return (a >= 'a') ? tmp.toLowerCase() : tmp;
    }).join("");
}
