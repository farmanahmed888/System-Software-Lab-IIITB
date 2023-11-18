import { Link } from "react-router-dom/cjs/react-router-dom.min";

const Account = () => {
    return (
        <div className="Account">
            <div className="account-page">
                <div className="container">
                    <div className="row">
                        <div className="col-3">
                            {/*1 column for image and other for form*/}
                            <img src={require("./img/user-2.png")} alt="user" />
                        </div>
                        <div className="col-3">
                            <div className="personal-details">Name</div>
                            <div className="personal-details">Email Address</div>
                            <div className="personal-details">Mobile Number</div>
                            <div className="personal-details">Password</div>
                        </div>
                        <div className="col-3">
                            <div className="personal-details">Mike Smith</div>
                            <div className="personal-details">mike.smith@mail.com</div>
                            <div className="personal-details">+91-1234567890</div>
                            <div className="personal-details">(not set)</div>
                        </div>
                        <Link to ="/" className="btn">
                            Edit →
                        </Link>
                    </div>
                </div>
            </div>
        </div>
    );
}

export default Account;