/**
 * Property Attribute
 * 
 * 1) 데이터 프로퍼티 - 키와 값으로 형성된 실질적 값을 갖고있는 프로퍼티
 * 2) 엑세서 프로퍼티 - 자체적으로 값을 갖고 있지 않지만 다른 값을 가져오거나
 *                     생성할때 호출되는 함수로 구성된 프로퍼티
 *                     예를들면 getter setter
 */
const yuJin = {
    name: '안유진',
    year: 2003,
};
console.log(Object.getOwnPropertyDescriptor(yuJin,'name'));
console.log(Object.getOwnPropertyDescriptor(yuJin,'year'));

/**
 * 1) Value - 실제 프로퍼티의 값
 * 2) writable - 값을 수정 할 수 있는지 여부. false로 설정하면 프로퍼티 값을 수정 할 수 없다
 * 3) enumerable - 열거가 가능한지 여부. for...in 룹 등을 사용할 수 있으면 true
 * 3) configurable - 프로퍼티 어트리뷰트의 재정의가 가능한지 여부를 판단
 *                   false 일 경우 프로퍼티 삭제나 어트리뷰트 변경이 금지된다.
 *                   단, writable이 true인 경우 값 변경과 writable 을 변경하는건 가능
 */
console.log(Object.getOwnPropertyDescriptors(yuJin));
console.log('--------------------------------------');
const yuJin2 = {
    name:'안유진',
    year:2003,

    get age(){
        return new Date().getFullYear() - this.year;
    },

    set age(age){
        this.year = new Date().getFullYear() - age;
    }
}
console.log(yuJin2);
console.log(yuJin2.age);
yuJin2.age = 32;
console.log(yuJin2.age);
console.log(yuJin2.year);
console.log('--------------------------------------');

console.log(Object.getOwnPropertyDescriptor(yuJin2,'age'));

// yuJin2['height'] = 172;
// console.log(yuJin2);
// console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));

Object.defineProperty(yuJin2,'height',{
    value:172,
    writable:true,
    enumerable:true,
    configurable:true,
    // 만약 defineProperty에서 위 값을 주지 않으면
    // 기본 값으로 false가 들어간다.
})
console.log(yuJin2);
console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));

yuJin2.height = 180;
console.log(yuJin2);

Object.defineProperty(yuJin2,'height',{
    writable:false,
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));
console.log('--------------------------------------');
yuJin2.height= 172; // writable:false 로 해놔서 깂이 위에 설정한 180 그대로임
console.log(yuJin2);
console.log('--------------------------------------');

/**
 * Enumerable
 */
console.log(Object.keys(yuJin2));
for(let key in yuJin2){
    console.log(key);
}
Object.defineProperty(yuJin2,'name',{
    enumerable:false, // 열거를 할 수 없게 된다
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'name'));
console.log('--------------------------------------');

console.log(Object.keys(yuJin2));
for(let key in yuJin2){
    console.log(key);
}
console.log(yuJin2);
console.log(yuJin2.name);
console.log('--------------------------------------');

/**
 * Configurable
 */
Object.defineProperty(yuJin2,'height',{
    writable:true,
    configurable: false,    
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));

// Object.defineProperty(yuJin2,'height',{
//     enumerable:false,
// });

Object.defineProperty(yuJin2,'height',{
    value:172,
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));

// writable : true > false 는 가능, value 값도 변경가능
Object.defineProperty(yuJin2,'height',{
    writable:false,
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));
// writable : false > true 는 불가
Object.defineProperty(yuJin2,'height',{
    writable:true,
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'height'));
