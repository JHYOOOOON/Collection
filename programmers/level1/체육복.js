function solution(n, lost, reserve) {
    let answer = 0;
    let arr = Array.from({length:n+1}, () => 1);
    for(let i of lost)
        arr[i]--;
    for(let i of reserve)
        arr[i]++;
    
    for(let i=1; i<=n; i++){
        if(arr[i] === 2 && arr[i-1] === 0){
            arr[i-1]++;
            arr[i]--;
        }else if(arr[i] === 2 && arr[i+1] === 0){
            arr[i]--;
            arr[i+1]++;
        }
    }
    
    for(let i=1; i<=n; i++)
        if(arr[i])
            answer++;
            
    return answer;
}
