function solution(commands) {
    const table = new Array(2501).fill("");
    const parent = new Array(2501).fill(0).map((_, index) => index);
    const answer = [];

    function find(x) {
        if (parent[x] === x)
            return x;
        return parent[x] = find(parent[x]);
    }

    function update(r, c, value) {
        const x = find((r - 1) * 50 + c);
        for (let i = 1; i <= 50 * 50; i++) {
            if (find(i) === x)
                table[i] = value;
        }
    }

    function updateValues(value1, value2) {
        for (let i = 1; i <= 50 * 50; i++) {
            if (table[i] === value1)
                table[i] = value2;
        }
    }

    function merge(r1, c1, r2, c2) {
        if (r1 === r2 && c1 === c2)
            return;

        const x = find((r1 - 1) * 50 + c1);
        const y = find((r2 - 1) * 50 + c2);

        if (x === y)
            return;

        parent[y] = x;

        const tmp = table[x] !== "EMPTY" ? table[x] : table[y];

        for (let i = 1; i <= 50 * 50; i++) {
            if (find(i) === x)
                table[i] = tmp;
        }
    }

    function unmerge(r, c) {
        const x = find((r - 1) * 50 + c);
        const tmp = table[x];

        for (let i = 1; i <= 50 * 50; i++) {
            find(i);
        }

        for (let i = 1; i <= 50 * 50; i++) {
            if (find(i) === x) {
                parent[i] = i;
                table[i] = "EMPTY";
            }
        }
        table[(r - 1) * 50 + c] = tmp;
    }

    function print(r, c) {
        const x = find((r - 1) * 50 + c);
        answer.push(table[x]);
    }

    for (let i = 1; i <= 50 * 50; i++) {
        parent[i] = i;
        table[i] = "EMPTY";
    }

    for (const command of commands) {
        const v = command.split(' ');
        let check = true;

        if (v[0] === "UPDATE") {
            check = false;
            if (v.length === 4) {
                update(parseInt(v[1]), parseInt(v[2]), v[3]);
            } else {
                updateValues(v[1], v[2]);
            }
        } else if (v[0] === "MERGE") {
            merge(parseInt(v[1]), parseInt(v[2]), parseInt(v[3]), parseInt(v[4]));
        } else if (v[0] === "UNMERGE") {
            unmerge(parseInt(v[1]), parseInt(v[2]));
        } else if (v[0] === "PRINT") {
            print(parseInt(v[1]), parseInt(v[2]));
        }
    }

    return answer;
}
