import { Request, Response, NextFunction, Router } from 'express';
import { NotFound, BadRequest, RequestTimeout } from 'http-errors';
import { DIContainer, MinioService, SocketsService } from '@app/services';
import { logger } from '../../../utils/logger';
import { request } from 'http';

export class ExampleController {

    /**
     * Apply all routes for example
     *
     * @returns {Router}
     */
    public applyRoutes(): Router {
        const router = Router();

        router.post('/treatSomeone',this.treatSomeone);
        router.post('/newPlayer',this.newPlayer);
        router.post('/timer',this.timer);
        router.post('/submitAnswer',this.submitAnswer);

        return router;
    }

    /**
     * Sens a message back as a response
     */
    public getMessage(req: Request, res: Response) {
        logger.info('e getMessage request print message');

        res.json({ message: 'hello' });
    }

    /**
     * Broadcasts a received message to all connected clients
     */
    public sendMessageToClients(req: Request, res: Response) {
        const message: string = req.body.message;
        const event: string = req.body.event;

        //Sending a broadcast message to all clients
        const socketService = DIContainer.get(SocketsService);
        socketService.broadcast(event, message);

        res.json({ message: 'ok' });

    }

    public treatSomeone(req: Request, res: Response){
        console.log("line 47 backend/example.controller.ts : START");
        const message: string = req.body.message;
        const event: string = req.body.event;

        const socketService = DIContainer.get(SocketsService);
        socketService.broadcast(event,message);
        res.json({ message: 'ok' });
        console.log("line 53 backend/example.controller.ts : FINISH");
    }


    public newPlayer(req: Request, res: Response){
        console.log("line 58 backend/example.controller.ts : START");
        const message: string = req.body.message;
        const event: string = req.body.event;

        const socketService = DIContainer.get(SocketsService);
        socketService.broadcast(event,message);
        res.json({ message: 'ok' });
        console.log("line 63 backend/example.controller.ts : FINISH");
        
    }

    public timer(req: Request , res: Response){
        console.log("line 72 backend/example.controller.ts : START");
        const message: string = req.body.message;
        const event: string = req.body.event;

        const socketService = DIContainer.get(SocketsService);
        socketService.broadcast(event,message);

        res.json({ message: 'ok' });
        console.log("line 78 backend/example.controller.ts : FINISH");
        
        
        
    }

    public submitAnswer(req: Request, res: Response){
        console.log("line 81 backend/example.controller.ts : START");
        const message: string = req.body.message;
        const event: string = req.body.event;

        const socketService = DIContainer.get(SocketsService);
        socketService.broadcast(event,message);
        res.json({ message: 'ok' });
        console.log("line 87 backend/example.controller.ts : FINISH");
        
    }

}
