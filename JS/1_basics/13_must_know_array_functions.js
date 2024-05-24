/**
 * Array Functions
 */
let iveMembers = [
    '안유진',
    '가을',
    '레이',
    '장원영',
    '리즈',
    '이서',
]
console.log(iveMembers);

// push()
console.log(iveMembers.push('코드팩토리'));
console.log(iveMembers);
console.log('-------------------------')

// pop() : 마지막 원소 삭제 후 반환
console.log(iveMembers.pop());
console.log(iveMembers);
console.log('-------------------------')

// shift() : 첫번째거 삭제 후 반환
console.log(iveMembers.shift());
console.log(iveMembers);

// unshift() : 첫번째에 넣는다
console.log(iveMembers.unshift('바보'));
console.log(iveMembers);
console.log('-------------------------')

// splice()
console.log(iveMembers.splice(0,3));
console.log(iveMembers);
console.log('-------------------------')

iveMembers = [
    '안유진',
    '가을',
    '레이',
    '장원영',
    '리즈',
    '이서',
];
/**
 * 아래부터는 원래 변수를 바꾸지 않는 함수
 * 새로운 arr 를 만들어 냄
 */
// concat()
console.log(iveMembers.concat('코드팩토리'));
console.log(iveMembers);
console.log('-------------------------')

// slice()
console.log(iveMembers.slice(0,3));// 0~2 인덱스 출력
console.log(iveMembers);
console.log('-------------------------')

// spread operator
let iveMembers2 = [
    ...iveMembers,
];
console.log(iveMembers2);
console.log('-------------------------')

let iveMembers3 = [
    iveMembers,
];
console.log(iveMembers3);
console.log('-------------------------')

let iveMembers4 = iveMembers;
console.log(iveMembers4);
console.log(iveMembers4 === iveMembers);

// console.log([
//     ...iveMembers,
// ] === iveMembers ) ; // false

// join()
console.log(iveMembers.join());



