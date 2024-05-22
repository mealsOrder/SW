/**
 * Data Types
 * 
 * 여섯개의 Primitive Type
 * 한개의 오브젝트 타입
 * 
 * 1) Number (숫자)
 * 2) String (문자열)
 * 3) Boolean (불리언)
 * 4) undefined (언디파인드)
 * 5) null  (널)
 * 6) Symbol (심볼)
 * 
 * 7) Object (객체)
 *      Function
 *      Array
 *      Object
 */

const age = 29;
const tem = -19;
const pi = 3.14;

console.log(age);
console.log(tem);
console.log(pi);
console.log('-------------------');

const inf = Infinity;
const nInf = -Infinity;

console.log(typeof inf);
console.log(typeof nInf);
console.log('-------------------');

/**
 * String Type
 */
const code = '"코"드팩토리';
console.log(typeof code);

const ive = "'아이브' 안유진 "
console.log(ive);
console.log('-------------------');
/**
 * Template Literal
 * 
 * Escaping Character
 * 1) newline -> \n
 * 2) tab -> \t
 * 3) 백슬래시 스트링으로 표현하고 싶다면 두번입력
 */
const i = '아이브\n안유진';
console.log(i);
const j = 'ive\tme';
console.log(j);
const k = 'ive\\me';
console.log(k);
const ho = 'ive\'code';
console.log(ho);

const v = `아이브1 '"\\\\///
장원영`;
console.log(v);
console.log(typeof v);

const name = 'jjj';
console.log(name +` ttt`);
console.log(`${name} 안`); // 리터럴
console.log('-------------------');
/**
 * Boolean type
 * O, X
 */
const isTrue = true;
const isFalse = false;
console.log(typeof isTrue);
console.log(typeof isFalse);
console.log('-------------------');
/**
 * undefined
 * 
 * 사용자가 직접 값을 초기화하지 않았을때 지정되는 값
 * 
 * 직접 undefined로 값을 초기화 하는건 지양
 */
let noInit;
console.log(noInit);
console.log(typeof noInit);
console.log('-------------------');
/**
 * null Type
 * 
 * undefined와 마찬가지로 값이 없다는 뜻이나
 * JS에서는 개발자가 명시적으로 없는 값으로 초기화 할때 사용
 * undefined와 다른 맥락
 */
let init = null;
console.log(init);
console.log(typeof init); // 원래는 null타입 이여야하지만
                          // object 타입으로 많이 쓰고 있어서 그냥 둔 아이
console.log('-------------------');
/**
 * Symbol type
 * 
 * 유일무이한 값을 생성할때 사용한다.
 * 다른 프리미티브 값들과 다르게 Symbaol 함수를
 * 호출해서 사용한다.
 */
const test1='1';
const test2='2';

console.log(test1===test2);

const symbol1 = Symbol('1');
const symbol2 = Symbol('1');

console.log(symbol1===symbol2);
console.log('-------------------');

/**
 * Object 타입
 * 
 * Map
 * 키:벨류의 쌍으로 이루어져있다
 * key:value
 */
const dic = {
    red: '빨강',
    org: '주황',
    yel: '노랑',
};
console.log(dic);
console.log(dic['red']);
console.log(dic['org']);
console.log(dic['yel']);

console.log(typeof dic);

/**
 * Array 타입
 * 
 * 값을 리스트로 나열 할 수 있는 타입
 */
const arr = [
    'a', //0
    'b', //1
    'c', //2
    'd',
    'e',
];
console.log(arr);

/**
 * index
 * 
 * 0부터 시작
 * 1씩 증가함
 */
console.log(arr[0]);
console.log(arr[5]);

arr[0] = 'ok';
console.log(arr);
console.log(typeof arr);

/**
 * static typing -> 변수를 선언할때 어떤 타입의 변수를 선언할지 명시
 * 
 * dynamic typing -> 변수의 타입을 명시적으로 선언하지 않고 갑에의해 타입의 "추론"한다
 * JS -> dynamic typing 이다.
 */
