/**
 * 이중 연결 리스트 노드 정의
 */
var ListNode = function(key, value) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
};

/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.map = new Map(); // Key -> Node 검색용 (O(1))
    
    // 더미 헤드와 테일 (경계 처리용)
    this.head = new ListNode(0, 0);
    this.tail = new ListNode(0, 0);
    
    // 초기 연결: Head <-> Tail
    this.head.next = this.tail;
    this.tail.prev = this.head;
};

// [보조 함수] 노드를 리스트에서 제거 (연결 끊기)
LRUCache.prototype.removeNode = function(node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
};

// [보조 함수] 노드를 맨 앞(Head 바로 뒤)에 추가
LRUCache.prototype.addToHead = function(node) {
    node.prev = this.head;
    node.next = this.head.next;
    
    this.head.next.prev = node;
    this.head.next = node;
};

/** * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    // 1. 없으면 -1 반환
    if (!this.map.has(key)) return -1;
    
    // 2. 있으면 노드 가져오기
    const node = this.map.get(key);
    
    // 3. 사용되었으므로 뽑아서 맨 앞으로 이동 (LRU 업데이트)
    this.removeNode(node);
    this.addToHead(node);
    
    return node.value;
};

/** * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    // 1. 이미 존재하는 키인 경우: 값 업데이트 후 맨 앞으로
    if (this.map.has(key)) {
        const node = this.map.get(key);
        node.value = value;
        this.removeNode(node);
        this.addToHead(node);
        return;
    }

    // 2. 새로운 키인데 용량이 가득 찬 경우: 꼬리(LRU) 제거
    if (this.map.size >= this.capacity) {
        const lruNode = this.tail.prev; // Tail 바로 앞이 가장 오래된 노드
        this.removeNode(lruNode);       // 리스트에서 제거
        this.map.delete(lruNode.key);   // 맵에서 제거
    }

    // 3. 새 노드 생성 및 추가
    const newNode = new ListNode(key, value);
    this.addToHead(newNode);
    this.map.set(key, newNode);
};