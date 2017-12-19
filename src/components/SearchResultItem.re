open! Helpers;

module Styles = SearchResultItemStyles;

type t = {.
  "_type": string,
  "slug": string,
  "name": string,
  "description": string,
  "stars": Js.nullable(string),
  "updated": Js.Date.t,
  "version": string
};

let component = ReasonReact.statelessComponent("SearchResultItem");
let make = (~package, ~onClick, _children) => {
	...component,

	render: _self =>
		<div className=Styles.root(package##_type) onClick=(_e => onClick(package))>
			<div>
				<span className=Styles.name> {package##name |> text} </span>
				<span className=Styles.version> {package##version |> text} </span>
				<span className=Styles.unpublishedLabel(package##_type)> {"unpublished" |> text} </span>

				<div className=Styles.description>	
					{package##description |> text}
				</div>
			</div>

			<div>
				<div className=Styles.updated> <TimeAgo date=package##updated /> </div>
				{
					switch (package##stars |> Js.toOption) {
					| Some(stars) => <div className=Styles.stars> {stars |> text} <Icon.Star className=Styles.starIcon/> </div>
					| None 				=> ReasonReact.nullElement
					}
				}
			</div>
		</div>
};
