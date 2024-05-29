/**
 * Static Keyword
 */
class IdolModel{
    name;
    year;
    static groupName = '아이브';
    constructor(name,year){
        this.name = name;
        this.year = year;
    }
    static returnGroupName(){
        return '아이브';
    }
}

const yuJin = new IdolModel('안유진',2003);
console.log(yuJin);

// static 키워드는 클래스 자체에서 접근
console.log(IdolModel.groupName);
console.log(IdolModel.returnGroupName());

/**
 * factory constructor
 */
class Myclass{
    name;
    year;

    constructor(name,year){
        this.name = name;
        this.year = year;
    }
    static fromObject(object){
        return new Myclass(
            object.name,
            object.year,
        );
    }
    static fromList(list){
        return new Myclass(
           list[0],
           list[1], 
        )
    }
}

const yujin2 = Myclass.fromObject({
    name: '안유진',
    year: 2003,
});
console.log(yujin2);

const wonYoung = Myclass.fromList([
    '장원영',
    2003,
]);
console.log(wonYoung);





