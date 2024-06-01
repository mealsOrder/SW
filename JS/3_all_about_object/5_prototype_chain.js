/**
 * Prototype
 */
const testObj = {};

// __proto__ : 모든 객체에 존재하는 프로퍼티
// class 강의에서 배울때 상속에서 부모 클래스에 해당되는 값이다.
console.log(testObj.__proto__);

function IdolModel(name,year){
    this.name = name;
    this.year = year;
}
console.log(IdolModel.prototype);

console.dir(IdolModel.prototype,{
    showHidden:true,
});

// circular reference : 서로가 서로를 참조하고 있는 상태
console.log(IdolModel.prototype.constructor === IdolModel);
console.log(IdolModel.prototype.constructor.prototype == IdolModel.prototype);

const yuJin = new IdolModel('안유진',2003);

console.log(yuJin.__proto__);
console.log(yuJin.__proto__ === IdolModel.prototype);

console.log(testObj.__proto__ === Object.prototype);
console.log('-----------------------------------------------------');

// key note 에 ??? 쳐져 있던 부분...
console.log(IdolModel.__proto__ === Function.prototype);
console.log(Function.prototype.__proto__ ===Object.prototype);
console.log(IdolModel.prototype.__proto__ === Object.prototype);

console.log(yuJin.toString());
console.log(Object.prototype.toString());

function IdolModel2(name, year){
    this.name=name;
    this.year=year;

    this.sayHello = function(){
        
    }
};


