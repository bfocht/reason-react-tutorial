let component = ReasonReact.statelessComponent("TodoItem");
let make = (~title, ~completed, _children) => {
    ...component,
    render: (self) =>
        <div className="item">
        <input
            _type="checkbox"
            checked=(Js.Boolean.to_js_boolean(completed))
        />
        (ReasonReact.stringToElement(title))
        </div>
};
