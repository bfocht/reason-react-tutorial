let component = ReasonReact.statelessComponent("TodoApp");

let make = (~name, children) => {
    ...component,
    render: (self) => {
        <div className="container">
            <h1 className="title"> (ReasonReact.stringToElement("To do list")) </h1>
            <button className="btn btn-primary" >
                (ReasonReact.stringToElement("Add Item"))
            </button>
            <hr />
            <div className="items">
                (ReasonReact.stringToElement("Nothing to do"))
            </div>
        </div>
    }
};
