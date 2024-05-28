/**
 * try...catch
 * 
 * 1) 발생시킬때 -> 던진다고 한다.(throw)
 * 2) 명시적으로 인지할때 -> 잡는다고 한다 (catch)
 */
function runner(){
    try{
        console.log('Hello');
        throw new Error('big problem!');
        console.log('Code Factory');
    }catch(e){
        console.log('----catch----');
        console.log(e);
    }finally{
        // try에서 에러가 나든 안나든 무조건 실행
        console.log('----finally----');        
 
    }
}
runner();
