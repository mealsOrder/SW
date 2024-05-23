/**
 * Loops
 * 
 * 1) for
 * 2) while
 */

for(let i=0;i<10;i++){
    console.log(i);
}

console.log('-------------');

let sq = '';
for(let i=0;i<6;i++){
    for(let j=0;j<6;j++){
        sq+= '*';
    }
    sq+='\n';
}
console.log(sq);
console.log('-------------');

/**
 * for...in
 */
const yuJin={
    name:'안유진',
    year:2003,
}


for(let key in yuJin){
    console.log(key);
}
console.log('-------------');

const iveArray = ['안유진','가을','레이','장원영','리즈','이서'];

for(let key in iveArray){
    console.log(key);
    console.log(`${key}:${iveArray[key]}`);
}
console.log('-------------');

/**
 * for...of
 */
for(let value of iveArray){
    console.log(value);
}
console.log('-------------');

/**
 * while
 */
let num = 0;

while(num<10){
    num++;
}
console.log(num);
console.log('-------------');

/**
 * do...while
 * 먼저 코드를 실행하고 조건을 판단함
 * 그냥 쓰지마라ㅋㅋ
 */
num = 0;
do{
    num++;
}while(num<10);
console.log('-------------');

/**
 * break
 */
for(let i=0;i<10;i++){
    if(i===5){
        break;
    }
    console.log(i);
}
console.log('-------------');

num=0;
while(num<10){
    if(num===5){
        break;
    }
    num++;
    console.log(num);
}
console.log('-------------');

/**
 * continue
 */
for(let i=0;i<10;i++){
    if(i===5){
        continue;
    }
    console.log(i);
}
console.log('-------------');

num=0;
while(num<10){
    num++;
    if(num===5){
        continue;
    }
    console.log(num);
}
console.log('-------------');



