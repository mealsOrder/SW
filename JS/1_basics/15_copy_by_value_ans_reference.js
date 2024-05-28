/**
 * copy by value 값에 의한 전달
 * copy by referenc 참조에 의한 전달
 * 
 * 1) 기본적으로 모든 primitive 값은 copy by value
 * 2) 객체는 copy by reference
 */
let original = '안녕하세요';
let clone = original;

console.log(original);
console.log(clone);

clone += ' 안유진 입니다.';
console.log('------------------');
console.log(original);
console.log(clone);

let originalObj = {
    name: '안유진',
    group: '아이브',
};
let cloneObj = originalObj;

console.log(originalObj);
console.log(cloneObj);
console.log('------------------');

originalObj['group'] = '코드팩토리';
console.log(originalObj);
console.log(cloneObj);

console.log(originalObj == cloneObj);
console.log(original === clone);

originalObj = {
    name: 'choi',
    group: 'code',
};
cloneObj = {
    name: 'choi',
    group: 'code',
};
console.log(originalObj === cloneObj);
console.log('------------------');

const yuJin1 = {
    name: '안유진',
    group: '아이브',
};
const yuJin2 = yuJin1;
const yuJin3 = {
    name: '안유진',
    group: '아이브',
}
console.log(yuJin1 === yuJin2);// t
console.log(yuJin1 === yuJin3);// f
console.log(yuJin2 === yuJin3);// f
console.log('------------------');

/**
 * Spread Operator : capy by value
 */
const yuJin4 = {
    ...yuJin3,
};
console.log(yuJin4);
console.log(yuJin4 === yuJin3);
console.log('------------------');

const yuJin5 = {
    year: 2003,
    ...yuJin3,
};
console.log(yuJin5);

const yuJin6 = {
    name:'code',
    ...yuJin3,
};
console.log(yuJin6);

const yuJin7 = {
    ...yuJin3,
    name:'code',
};
console.log(yuJin7);

const numbers = [1,3,5];
const numbers2 = [
    ...numbers,
    10,
];

console.log(numbers2);
