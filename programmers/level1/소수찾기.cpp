int answer = 2;
    bool flag = true;
    vector<int>v;
    
    if(n<=3){return n-1;}
    else{
        for(int i=4;i<=n;i++){
            flag=true;
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){flag=false; break;}
            }
            if(flag==true){answer++;}
        }
    }
    
    return answer;
}

// 효율성 테스트는 통과 못함
