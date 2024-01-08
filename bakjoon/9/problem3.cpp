#include <bits/stdc++.h>

using namespace std;

void addIntend(int num){
    for (int i = 0; i < num; i++)
    {
        cout << "____";
    }
    
}
void chatbot(int depth, int end){
    addIntend(depth);
    cout << "\"재귀함수가 뭔가요?\"" << endl;
    if (depth != end){
        addIntend(depth);
        cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
        addIntend(depth);
        cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
        addIntend(depth);
        cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
        chatbot(depth + 1, end);
    }else{
        addIntend(depth);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
    }
    addIntend(depth);
    cout << "라고 답변하였지." << endl;
}

int main(int argc, const char** argv) {
    int input;
    cin >> input;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    chatbot(0, input);
    return 0;
}  