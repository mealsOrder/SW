/**
 * Getter ans Setter
 */
class IdolModel{
    name;
    year;
    constructor(name,year){
        this.name = name;
        this.year = year;
    }
    /**
     * 1) 데이터를 가공해서 새로운 데이터를 반환
     * 2) private한 값을 반환할때
     * 3) 함수처럼 써놨지만 함수처럼 부르면 에러남
     */
    get nameAndYear(){
        return `${this.name}-${this.year}`;
    }
    set setName(name){
        this.name = name;
    }
}
const yuJin = new IdolModel('안유진',2003);
console.log(yuJin);
console.log(yuJin.nameAndYear);

yuJin.setName = '장원영';
console.log(yuJin);
console.log('-------------');

class IdolModel2{
    #name; // private
    year;

    constructor(name,year){
        this.#name=name;
        this.year=year;
    }
    get name(){
        return this.#name;
    }
    set name(name){
        this.#name = name;
    }
}
const yuJin2 = new IdolModel2('안유진',2003);
console.log(yuJin2);
console.log(yuJin2.name);

yuJin2.name='code';
console.log(yuJin2.name);

