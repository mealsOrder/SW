/**
 * Class Keyword
 */
class IdolModel{
    name;
    year;

    constructor(name,year){
        this.name = name;
        this.year = year;
    }
    sayName(){
        return `안녕하세요 저는 ${this.name} 입니다.`
    }
}

// constructor - 생성자

const yuJin = new IdolModel('안유진',2003);
console.log(yuJin);
const gaeul = new IdolModel('가을',2002);
console.log(gaeul);

console.log(yuJin.name);
console.log(yuJin.year);

console.log(yuJin.sayName());
console.log(gaeul.sayName());

console.log(typeof IdolModel);
console.log(typeof yuJin);
