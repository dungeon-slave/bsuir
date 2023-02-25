"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Server = void 0;
const express_1 = __importDefault(require("express"));
const Tasks_1 = require("./Tasks");
const express_fileupload_1 = __importDefault(require("express-fileupload"));
class Server {
    port;
    app;
    parser;
    fileUpload;
    filter;
    constructor(port) {
        this.port = port;
        this.parser = require('body-parser');
        this.app = (0, express_1.default)();
        this.filter = "-";
        this.app.set('view engine', 'ejs');
        this.app.use((0, express_fileupload_1.default)());
        this.app.use(this.parser.json());
        this.app.use(this.parser.urlencoded({ extended: true }));
    }
    checkServer() {
        console.log("Server is running");
    }
    sendPage(req, res) {
        res.render('index', { "tasks": Tasks_1.tasks, "filter": this.filter });
    }
    sendFile(req, res) {
        res.end(Tasks_1.tasks.find(f => f.file.name == req.query.fileName).file.data);
    }
    getTask(req, res) {
        if (!req.files) {
            res.send("File was not uploaded!");
            return;
        }
        let file = req.files.taskfile;
        Tasks_1.tasks.push(new Tasks_1.Task(req.body.name, req.body.date, req.body.status, file));
        res.redirect('/');
    }
    getFilter(req, res) {
        this.filter = req.body.filter;
        res.redirect('/');
    }
}
exports.Server = Server;
