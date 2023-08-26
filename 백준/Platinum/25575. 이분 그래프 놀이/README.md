# [Platinum V] 이분 그래프 놀이 - 25575 

[문제 링크](https://www.acmicpc.net/problem/25575) 

### 성능 요약

메모리: 3556 KB, 시간: 592 ms

### 분류

이분 탐색, 그리디 알고리즘, 정렬

### 문제 설명

<p>Bob은 이분 그래프 (Bipartite Graph)를 이용한 놀이를 즐겨한다. 이 문제에서는 아래와 같이 임의의 이분 그래프 $H = (X + Y, E)$를 정의한다:</p>

<ul>
	<li>$n$개의 노드 집합 $X = \{x_1, x_2, \dots, x_n \}$ 과 $m$개의 노드 집합 $Y = \{ y_1, y_2, \dots, y_m\}$ 은 분리되어 있고, 따라서 $H$의 모든 간선은 $X$의 노드 중 하나와 $Y$의 노드 중 하나를 연결한다.</li>
	<li>간선 집합은 $E = \{ e_1, e_2, \dots, e_k \}$로 나타낸다.</li>
</ul>

<p>Bob은 아래 규칙에 따라 이분 그래프 놀이를 한다:</p>

<ul>
	<li>$X$의 각 노드 $x_i$에 서로 다른 1부터 n 사이의 정수 가중치 $v_i$를 부여한다. (즉, $1 \leq i \leq n$ 인 $i$에 대하여 $1 \leq v_i \leq n$, $v_i \in \mathbb{Z}$ 이고 $i \neq j$ 일 때 $v_i \neq v_j$ 이다.)</li>
	<li>$Y$의 각 노드 $y_j$에 서로 다른 1부터 m 사이의 정수 가중치 $w_j$를 부여한다 (즉, $1 \leq j \leq m$인 $j$에 대하여 $1 \leq w_j \leq m$, $w_j \in \mathbb{Z}$ 이고 $i \neq j$ 일 때 $w_i \neq w_j$ 이다.)</li>
	<li>위 가중치를 토대로 각 간선 $e = (x_i, y_j)$ 에 대해 간선의 가중치는 $v_i + w_j$ 로 정의한다.</li>
	<li>이분 그래프 H의 "점수"는 모든 간선의 가중치 합으로 정의한다.</li>
</ul>

<p>예를 들어 X = {x<sub>1</sub>, x<sub>2</sub>}, Y = {y<sub>1</sub>, y<sub>2</sub>}, E = {(x<sub>1</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>2</sub>)}라 하자 (아래 그림 참고).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/48591093-e5a3-4c92-ae62-90cd5a139c79/-/preview/" style="height: 250px; width: 290px;"></p>

<p>이 때 위 규칙에 따라 노드들에 가중치를 부여하는 방법은 총 2! × 2! = 4가지 존재한다.</p>

<ul>
	<li>만약 v<sub>1</sub> = 1, v<sub>2</sub> = 2이고 w<sub>1</sub> = 1, w<sub>2</sub> = 2라면: e<sub>1</sub> = v<sub>1</sub> + w<sub>1</sub> = 2, e<sub>2</sub> = v<sub>2</sub> + w<sub>1</sub> = 3, e<sub>3</sub> = v<sub>2</sub> + w<sub>2</sub> = 4가 되어 H의 점수는 9가 된다.</li>
	<li>만약 v<sub>1</sub> = 1, v<sub>2</sub> = 2이고 w<sub>1</sub> = 2, w<sub>2</sub> = 1라면: e<sub>1</sub> = v<sub>1</sub> + w<sub>1</sub> = 3, e<sub>2</sub> = v<sub>2</sub> + w<sub>1</sub> = 4, e<sub>3</sub> = v<sub>2</sub> + w<sub>2</sub> = 3가 되어 H의 점수는 10이 된다.</li>
	<li>만약 v<sub>1</sub> = 2, v<sub>2</sub> = 1이고 w<sub>1</sub> = 1, w<sub>2</sub> = 2라면: e<sub>1</sub> = v<sub>1</sub> + w<sub>1</sub> = 3, e<sub>2</sub> = v<sub>2</sub> + w<sub>1</sub> = 2, e<sub>3</sub> = v<sub>2</sub> + w<sub>2</sub> = 3가 되어 H의 점수는 8이 된다.</li>
	<li>만약 v<sub>1</sub> = 2, v<sub>2</sub> = 1이고 w<sub>1</sub> = 2, w<sub>2</sub> = 1라면: e<sub>1</sub> = v<sub>1</sub> + w<sub>1</sub> = 4, e<sub>2</sub> = v<sub>2</sub> + w<sub>1</sub> = 3, e<sub>3</sub> = v<sub>2</sub> + w<sub>2</sub> = 2가 되어 H의 점수는 9가 된다.</li>
</ul>

<p>H의 "최대 점수"는 위와 같이 가능한 모든 가중치를 부여하는 방법 중 H의 점수를 최대화 했을 때 얻을 수 있는 점수로 정의하자 -- 편의상 이를 S(H)라 하자. Bob은 임의의 이분 그래프 H의 "최대 점수"를 구하는 놀이를 즐겨하지만 이제 너무 잘하게 되어 지루해하던 참이다.</p>

<p>마침 이를 지켜보던 Alice는 새로운 놀이를 제안했다. 그래프 H의 간선 중 임의로 i번째 간선을 지워 새로운 이분 그래프를 얻을 수 있는데, 이를 H<sub>i</sub>라 하자 (아래 그림 참고).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/85152b30-80e3-4984-ae32-5ee6a4287afd/-/preview/" style="height: 264px; width: 290px;"><img alt="" src="https://upload.acmicpc.net/3ef6d24a-139f-4d5e-89db-1a5f962bed5b/-/preview/" style="height: 265px; width: 290px;"><img alt="" src="https://upload.acmicpc.net/999d09b9-61b2-4afa-a6b0-f045eabba248/-/preview/" style="height: 266px; width: 290px;"></p>

<p>S(H<sub>i</sub>)는 그래프 H<sub>i</sub>의 "최대 점수"이며 상기한 정의에 따라 구할 수 있다. 예를 들어 위의 예제에서 H<sub>1</sub>은 원래 그래프 H에서 (x<sub>1</sub>, y<sub>1</sub>)을 삭제한 그래프이며, 이 때 S(H<sub>1</sub>)은 7이다 (이를 달성하려면 v<sub>1</sub> = 1, v<sub>2</sub> = 2 이어야 한다). 같은 예제에서 H<sub>2</sub>은 (x<sub>2</sub>, y<sub>1</sub>)을 삭제한 그래프이며, 이 때 (v<sub>1</sub>, v<sub>2</sub>, w<sub>1</sub>, w<sub>2</sub>) 값에 관계없이 S(H<sub>2</sub>)는 6이다. S(H<sub>3</sub>)은 7이며, 따라서 이 경우 S(H<sub>1</sub>), S(H<sub>2</sub>), S(H<sub>3</sub>) 의 최댓값은 7이다.</p>

<p>Alice의 제안대로 Bob은 S(H)뿐 아니라 S(H<sub>1</sub>), S(H<sub>2</sub>), ..., S(H<sub>k</sub>)의 최댓값을 구해보려고 한다. Bob을 도와주자.</p>

### 입력 

 <p>입력 첫 줄에 테스트 케이스의 수 T가 주어진다.</p>

<p>각 테스트 케이스의 첫 줄에는 n, m, k가 공백으로 구분되어 주어진다. 다음 k개의 줄에는 각 줄에 간선을 나타내는 2개의 정수가 공백으로 구분되어 주어지며 X의 노드 인덱스와 Y의 노드 인덱스를 나타낸다 (즉, x<sub>i</sub>와 y<sub>j</sub>를 잇는 간선은 "i j"로 주어진다).</p>

### 출력 

 <p>각 테스트 케이스의 정답인 두 개의 정수를 각 줄에 출력한다. 첫 번째 정수는 S(H)이며 두 번째 정수는 S(H<sub>1</sub>), ..., S(H<sub>k</sub>)의 최댓값이다.</p>

