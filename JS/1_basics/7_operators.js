/**
 * 1) 덧셈
 * 2) 뺄셈
 * 3) 곱셈
 * 4) 나눗셈
 * 5) 나머지
 */

console.log(10+10);
console.log(10-10);
console.log(10*10);
console.log(10/10);
console.log(10%10);
console.log('-------------');

/**
 * 증가와 감소
*/
let num=1;
num++;
console.log(num);
num--;
console.log(num);
console.log('-------------');

/**
 * 연산자의 위치
*/
let res = 1;
console.log(res);

res=num++;
console.log(res,num);

res = num--;
console.log(res,num);

res= ++ num;
console.log(res,num);

res= --num;
console.log(res,num);

console.log('-------------');

/**
 * 숫자 타입이 아닌 타입에 +,- 사용하면 어떻게 될까?
*/

let sample = '99';
console.log(+sample);
console.log(typeof +sample);

console.log(sample);
console.log(typeof sample);

sample=true;
console.log(+sample);
console.log(typeof +sample);

sample=false;
console.log(+sample);
console.log(typeof +sample);

sample='안유진';
// Nan -> Not a Number
console.log(+sample);

sample='99';
console.log(-sample);
console.log(typeof -sample);
console.log('-------------');

/**
 * 할당 연산자 (assignment operator)
 */
num = 100;
console.log(num);

num+=10;
console.log(num);

num -=10;
console.log(num);

num *=10;
console.log(num);

console.log('-------------');

/**
 * 비교 연산자
 * 1) 값의 비교
 * 2) 값과 타입의 비교
 */

console.log(5==5);
console.log(5=='5');
console.log(0 == ' ');
console.log(true == 1);
console.log(false == 0);
console.log(true == '1');
console.log('-------------');

console.log(5===5);
console.log(5==='5');
console.log(0 === ' ');
console.log(true === 1);
console.log(false === 0);
console.log(true === '1');
console.log('-------------');

console.log(5!=5);
console.log(5!='5');
console.log(0 != ' ');
console.log(true != 1);
console.log(false != 0);
console.log(true != '1');
console.log('-------------');

console.log(5!==5);
console.log(5!=='5');
console.log(0 !== ' ');
console.log(true !== 1);
console.log(false !== 0);
console.log(true !== '1');
console.log('-------------');

/**
 * 대소 관계 비교 연산자
 */
console.log(100>1);
console.log(100<1);
console.log(100>=1);
console.log(100<=1);
console.log('-------------');

/**
 * 삼항 조건 연산자 (ternary operator)
 */
console.log(10>0 ? '10이 0보다 크다':'10이 0보다 작다;');
console.log('-------------');

/**
 * 논리 연산자
 * 1) && (and)
 * 2) || (or)
 */

// &&조건은 모두 true여야 true를 반환한다.
console.log(true&&true);
console.log(true&&false);
console.log(false&&true);
console.log(false&&flase);

console.log('-------------');

// ||는 하나만 true여도 true를 반환
console.log(true||true);
console.log(false||true);
console.log(true||false);
console.log(false||false);

console.log('-------------');

/**
 * 단축평가 (short circuit evaluation) 암기 영역
 * 
 * &&를 사용했을때 좌측이 true면 우측 값 반환
 * &&를 사용했을떄 좌측이 false면 좌측 값 반환
 * ||를 사용했을때 좌측이 true면 좌측 값 반환
 * ||를 사용했을때 좌측이 false면 우측 값 반환
 */
console.log(true||'아이브');
console.log(false||'아이브');
console.log(false&&'아이브');
console.log(true&&'아이브');

console.log(true&&true&&'아이브');
console.log(true&&false&&'아이브');
console.log('-------------');

/**
 * 지수 연산자
 */
console.log(2 ** 2);
console.log(10 ** 3);
console.log('-------------');

/**
 * null 연산자
 * ??를 사용할때 좌측값이 null이나 undefined 우측값을 반환
 */
let name;
console.log(name);

name = name ?? '코드';
console.log(name);

name = name ?? '아이브';
console.log(name);

let name2;
name2 ??= '코드팩토리';
console.log(name2);






