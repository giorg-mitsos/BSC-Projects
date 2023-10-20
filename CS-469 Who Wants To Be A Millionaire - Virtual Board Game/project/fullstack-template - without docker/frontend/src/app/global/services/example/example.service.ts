import {HttpClient} from '@angular/common/http'
import {Injectable} from '@angular/core';
import {environment} from 'src/environments/environment';

@Injectable({

    providedIn: 'root'
})

export class ExampleService{

    private hostURI: string;

    constructor (private http: HttpClient){
        this.hostURI = environment.host;
    }

    public treatSomeone(foodToTreat, toUserID, fromUserID){
        console.log("line 19 FRONTEND/example.service.ts : START - return");
        return this.http.post(`${this.hostURI}/api/example/treatSomeone`,
        {
            message:{
                food: foodToTreat,
                userID: toUserID,
                fromUserID: fromUserID
            }
            ,event: "treating"
        })
        
    }

    
    public newPlayer(uid){
        console.log("line 34 FRONTEND/example.service.ts : START - return");
        return this.http.post(`${this.hostURI}/api/example/newPlayer`,
        {
            message: uid,
            event: "newplayer"
        })
    }

    public timer(state){
        console.log("line 44 FRONTEND/example.service.ts : START - return");

        return this.http.post(`${this.hostURI}/api/example/timer`,
        {
            message: state,
            event: "timer"
        })
    }

    public submitAnswer(status){
        console.log("line 54 FRONTEND/example.service.ts : START - return");

        return this.http.post(`${this.hostURI}/api/example/submitAnswer`,
        {
            message: status,
            event: "submitAnswer"
        })
    }



}