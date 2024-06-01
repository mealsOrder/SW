/**
 * Immutable Object
 */
const yuJin = {
    name: '안유진',
    year:2003,

    get age(){
        return new Date().getFullYear() - this.year;
    },
    set age(age){
        this.year = new Date().getFullYear() - age;
    }
}
console.log(yuJin);

/**
 * Extensible : 확장이 가능한가? 기본값 true
 */
console.log(Object.isExtensible(yuJin));

yuJin['position']='vocal';
console.log(yuJin);
Object.preventExtensions(yuJin); // preventExtensions 로 확장 막음
console.log(Object.isExtensible(yuJin));

yuJin['groupName']='아이브'; // 확장을 막아놔서 그룹네임 추가 안됨
console.log(yuJin);

delete yuJin['position']; // 삭제는 된다!
console.log(yuJin);
console.log('-----------------------------------------------------');
/**
 * Seal : 봉인이 되어 있냐? 기본값 false
 */
const yuJin2 = {
    name: '안유진',
    year:2003,

    get age(){
        return new Date().getFullYear() - this.year;
    },
    set age(age){
        this.year = new Date().getFullYear() - age;
    }
}
console.log(yuJin2);
console.log(Object.isSealed(yuJin2));
Object.seal(yuJin2); // seal 이라는 스테틱 함수로 yujin2 를 봉인함
console.log(Object.isSealed(yuJin2));

yuJin2['groupName'] = '아이브'; // 봉인을 해놔서 값이 추가가 안됨
console.log(yuJin2); 

delete yuJin2['name']; // 봉인을 해놔서 삭제도 안됨, 주의 에러도 나지 않음
console.log(yuJin2);

// seal을 하니까 configurable 을 false 로 변경됨
Object.defineProperty(yuJin2,'name',{
    writable:false,
});
console.log(Object.getOwnPropertyDescriptor(yuJin2,'name'));
console.log('-----------------------------------------------------');

/**
 * Freezed
 * 읽기 이외의 모든 기능을 불가능하게 만든다
 */
const yuJin3 = {
    name: '안유진',
    year:2003,

    get age(){
        return new Date().getFullYear() - this.year;
    },
    set age(age){
        this.year = new Date().getFullYear() - age;
    }
}
console.log(Object.isFrozen(yuJin3));

Object.freeze(yuJin3);  // 동결 시켜버림
console.log(Object.isFrozen(yuJin3));

yuJin3['groupName'] = '아이브'; // 값을 추가
console.log(yuJin3); // 동결 시켜놔서 추가가 안됨

delete yuJin3['name']; // name 삭제
console.log(yuJin3); // 동결 시켜놔서 삭제도 안됨

// Object.defineProperty(yuin3,'name',{
//     value:'코드', // value 값 변경도 안됨
// });
console.log(Object.getOwnPropertyDescriptor(yuJin3,'name'));

const yuJin4 = {
    name:'안유진',
    year:2003,
    wonYoung:{
        name:'장원영',
        year:2002,
    },
};
Object.freeze(yuJin4);
console.log(Object.isFrozen(yuJin4));
console.log(Object.isFrozen(yuJin4['wonYoung']))

