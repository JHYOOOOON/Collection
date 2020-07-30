function solution(numbers) {
    let str = numbers.sort((a, b) => {
        let tmp_a = a.toString();
        let tmp_b = b.toString();
        return (tmp_b + tmp_a) - (tmp_a + tmp_b);
    }).join('');
    
    return (str[0] === '0') ? "0" : str;
}
