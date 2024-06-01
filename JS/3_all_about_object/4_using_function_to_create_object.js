/**
 * Using function to create objects
 */
function IdolModel(name,year){
    if(!new.target){// new 키워드가 사용되었는지 확인 해서 undefined 이면
        return new IdolModel(name,year); // new 키워드 붙여준다.
    }       
    this.name = name;
    this.year = year;
    //return {}; <- 이렇게 쓰지마라! primitive 는 반환 가능 ex) return 123;
    this.dance = function(){
        return `${this.name}이 춤을 춥니다.`;
    }
}
const yuJin = new IdolModel('안유진',2003);
console.log(yuJin);
//console.log(yuJin.dance());
const yuJin2 = IdolModel('가을',2002); // new 키워드를 붙이지 않으면 undefined 
console.log(yuJin2); // name, year가 안뜬다 그럼 어디 갔냐?
//console.log(global.name); // global 에 가있다.

// 화살표 함수로는 생성자 함수로 사용할 수 없다! 
// const IdolModelArrow = (name,year=>{
//     this.name = name;
//     this.year = year;
// });
// const yuJin3 = new IdolModelArrow('안유진',2003);
