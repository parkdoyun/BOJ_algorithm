# [Gold IV] 도깨비불 - 18109 

[문제 링크](https://www.acmicpc.net/problem/18109) 

### 성능 요약

메모리: 2176 KB, 시간: 0 ms

### 분류

많은 조건 분기, 구현, 문자열

### 제출 일자

2023년 10월 19일 15:58:00

### 문제 설명

<p style="text-align: center;"><img alt="2-set and QWERTY keyboard" src="https://upload.acmicpc.net/174db09b-1afb-412c-90b9-4c397df888a8/" style="width: 1000px;"></p>

<p>한글 두벌식 자판을 사용하다 보면, 다른 입력 방식에서는 찾아보기 힘든 <strong>도깨비불 현상</strong>이라는 특이한 현상을 경험할 수 있다. 예를 들어 “<em>서강대학교</em>”를 입력할 때 글쇠 입력 하나하나를 추적해 보자:</p>

<pre>ㅅ
서
<strong>석</strong>
<strong>서가</strong>
서강
서강ㄷ
서강대
<strong>서강댛
서강대하</strong>
서강대학
서강대학ㄱ
서강대학교</pre>

<p>“석” 에서 “서가”로 변할 때, 다음 글자의 초성이 될 자음이 입력하고 있는 글자의 종성 위치에 먼저 붙는 현상이 일어난다. 이를 ‘<strong>도깨비불 현상</strong>’이라고 한다.</p>

<p>“서강대학교”를 입력할 때는 도깨비불 현상이 2회 발생했다. 다른 예시도 보자.</p>

<table class="table table-bordered" style="width: 500px;">
	<tbody>
		<tr>
			<th>입력</th>
			<th>영문 모드 입력</th>
			<th>도깨비불 횟수</th>
		</tr>
		<tr>
			<td>이보세요</td>
			<td>dlqhtpdy</td>
			<td>3회</td>
		</tr>
		<tr>
			<td>코딩하기 싫다</td>
			<td>zheldgkrl tlfgek</td>
			<td>2회</td>
		</tr>
		<tr>
			<td>마춤뻐비 틀려써요</td>
			<td>akcnaQjql xmffuTjdy</td>
			<td>4회</td>
		</tr>
	</tbody>
</table>

<ul>
	<li>이보세요 : (“입” → “이보”), (“이봇” → “이보세”), (“이보셍” → “이보세요”)</li>
	<li>코딩하기 싫다 : (“콛” → “코딩”), (“코딩학” → “코딩하기”)</li>
	<li>마춤뻐비 틀려써요 : (“맟” → “마추”), (“마춤뻡” → “마춤뻐비”), (“마춤뻐비 틀렸” → “마춤뻐비 틀려써”), (“마춤뻐비 틀려썽” → “마춤뻐비 틀려써요”)</li>
</ul>

<p>문자열이 주어지면 그 문자열을 키보드로 입력했을 때 도깨비불 현상의 횟수를 계산해보자.</p>

### 입력 

 <p>첫 번째 줄에 공백 문자(<code><tt><span style="background-color:#dddddd;"> </span></tt></code>)와 완성형 한글들로 이루어진 한글 문자열을 영문 입력 모드에서 타이핑했을 때 입력되는 문자열이 주어진다. 문자열의 길이는 1 이상 10<sup>4</sup> 이하이다.</p>

### 출력 

 <p>입력으로 주어진 문자열을 한글 입력 모드로 타이핑했을 때 발생하는 도깨비불 현상의 횟수를 출력하라.</p>

