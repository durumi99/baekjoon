#include <bits/stdc++.h>

using namespace std;

set <int> ownCards;
set <int> thrownCards;

bool canMakeByCards(int target, set <int>& A, set <int>& B) {
    for (auto iter = A.begin(); iter != A.end(); iter++) {
        auto iter2 = B.find(target - *iter);
        if(iter2 != B.end()) {
            // cout << *iter << ' ' << *iter2 << '\n';
            int a = *iter;
            int b = *iter2;
            A.erase(a);
            B.erase(b);
            return true;
        }
    }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int i = 0;
    int n = cards.size() + 1;
    
    for ( ; i < cards.size() / 3 ; i++) {
        ownCards.insert(cards[i]);
    }
    
    
    for ( ; i < cards.size() ; i += 2) {
        // cout << "round : " << answer << '\n';
        // cout << "coin : " << coin << '\n';
        
        thrownCards.insert(cards[i]);
        thrownCards.insert(cards[i + 1]);
        if (canMakeByCards(n, ownCards, ownCards)) { // 가진 카드들로 n+1 을 만들 수 있는 경우
            // cout << "coin 0개 소모\n";
        } else if (coin >= 1 && canMakeByCards(n, ownCards, thrownCards)) { // 버린 카드 중 1장을 가져와야 만들 수 있는 경우
            coin--;
            // cout << "coin 1개 소모\n";
        } else if (coin >= 2 && canMakeByCards(n, thrownCards, thrownCards)){ // 버린 카드 중 2장을 가져와야 만들 수 있는 경우
            coin -= 2;
            // cout << "coin 2개 소모\n";
        } else {
            break;
        }
        answer++;
    }
    return answer;
}