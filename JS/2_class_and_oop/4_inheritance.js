/**
 * Inheritance
 */
class IdolModel{
    name;
    year;

    constructor(name,year){
        this.name=name;
        this.year=year;
    }
}


class FemaleIdolModel extends IdolModel{
    dance(){
        return '여자 아이돌이 춤을 춥니다.';
    }
}

class MaleIdolModel extends IdolModel{
    sing(){
        return '남자 아이돌이 노래를 부릅니다.';
    }
}

const yujin = new FemaleIdolModel('안유진',2003);
console.log(yujin);

const jiMin = new MaleIdolModel('지민',1995);
console.log(jiMin);

console.log(yujin.dance());
console.log(yujin.name);

console.log(jiMin.sing());
console.log(jiMin.year);
