import { UploadedFile } from "express-fileupload";

export let tasks: Array<Task> = [];

export class Task
{
    public name: string;
    public date: Date;
    public status: string;
    public file: UploadedFile;
    
    constructor(name: string, date: Date, status: string, file: UploadedFile)
    {
        this.name = name;
        this.date = date;
        this.status = status;
        this.file = file;
    }
}