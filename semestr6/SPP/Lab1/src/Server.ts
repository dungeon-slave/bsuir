import express, { Response, Request } from 'express';
import { Task, tasks } from './Tasks';
import fileUpload, { UploadedFile } from "express-fileupload";

export class Server
{
    readonly port:       number;
    readonly app:        any;
    readonly parser:     any;
    readonly fileUpload: any;
    public filter: string;

    constructor(port: number)
    {
        this.port = port;
        this.parser = require('body-parser');
        this.app = express();
        this.filter = "-";

        this.app.set('view engine', 'ejs');
        this.app.use(fileUpload());
        this.app.use(this.parser.json());
        this.app.use(this.parser.urlencoded({ extended: true }));
    }
    checkServer() : void
    {
        console.log("Server is running");
    }
    sendPage(req: Request, res: Response) : void
    {
        res.render('index', { "tasks": tasks, "filter": this.filter });
    }
    sendFile(req: Request, res: Response) : void
    {
        res.end(tasks.find(f => f .file.name == req.query.fileName)!.file.data);
    }
    getTask(req: Request, res: Response) : void
    {
        if (!req.files) 
        {
            res.send("File was not uploaded!");
            return;
        }
        let file = req.files.taskfile as UploadedFile;
        tasks.push(new Task(req.body.name, req.body.date, req.body.status, file));
        res.redirect('/');
    }
    getFilter(req: Request, res: Response) : void
    {
        this.filter = req.body.filter;
        res.redirect('/');
    }
}