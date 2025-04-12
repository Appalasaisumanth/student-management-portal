from datetime import timedelta
from flask import Flask, jsonify, request, Blueprint
import import_ipynb  # noqa: F401
from database import (
    insert_user,
    login_user,
    get_student,
    get_all_students,
    delete_student,
    insert_student,
    update_student,get_all_issues,get_student_issue,add_issue,delete_issue,create_menu,get_menu,student_vote,
    finalize_menu,delete_votes
)
from flask_jwt_extended import (
    JWTManager,
    create_access_token,
    jwt_required,
    get_jwt_identity,
)

app = Flask(__name__)
admin_bp = Blueprint("admin", __name__)
student_bp = Blueprint("student", __name__)
app.config["JWT_SECRET_KEY"] = "your_secret_key_here"  # Change this in production
app.config["JWT_ACCESS_TOKEN_EXPIRES"] = timedelta(hours=1)  # Token expires in 1 hour
jwt = JWTManager(app)


@app.route("/")
def home():
    return "welcome to server"


@app.route("/register", methods=["POST"])
def register():
    data = request.get_json()
    if "username" not in data.keys() or "password" not in data.keys():
        return jsonify({"error": "must contain username and password"}), 400
    elif "description" not in data.keys():
        if insert_user(username=data["username"], password=data["password"])[0]:
            return jsonify({"status": "sucessful register"}), 200
        else:
            return jsonify({"error": "existing user "}), 400
    elif "admin" not in data.keys():
        if insert_user(
            username=data["username"],
            password=data["password"],
            description=data["description"],
        )[0]:
            return jsonify({"status": "successful register"}), 200
        else:
            return jsonify({"error": "existing user "}), 400
    else:
        if insert_user(
            username=data["username"],
            password=data["password"],
            description=data["description"],
            admin=True,
        )[0]:
            return jsonify({"status": "sucessful register for admin"}), 200
        else:
            return jsonify({"error": "existing user "}), 400


@app.route("/login", methods=["POST"])
def login():
    data = request.get_json()
    if "username" not in data.keys() or "password" not in data.keys():
        return jsonify({"error": "either of username or password are missing "}), 400
    result = login_user(username=data["username"], password=data["password"])
    if result[0]:
        access_token = create_access_token(
            identity=("admin+" if result[1] else "student+") + data["username"]
        )  # Create JWT token
        return jsonify({"Token": access_token, "message": "successful login"}), 200
    else:
        return jsonify({"message": "login failed,try some other time"}), 400


# @admin_bp.before_request
@jwt_required()
def check_admin():
    current_user = get_jwt_identity()  # Get username from token
    is_admin = current_user.split("+")
    if is_admin[0] == "admin":
        return (
            jsonify(message=f"Hello, {is_admin[1]}! Welcome to the admin panel."),
            200,
        )
    else:
        return jsonify(message="invalid credentials"), 403


# Admin Home
@admin_bp.route("/", methods=["GET"])
def admin_home():
    return jsonify(message="Welcome to the admin panel."), 200


@admin_bp.route("/students", methods=["GET"])
def admin_students():
    page, limit = 0, 10
    page = int(request.args["page"]) if "page" in request.args else 0
    limit = int(request.args["limit"]) if "limit" in request.args else 10
    result = get_all_students(page=page, limit=limit)
    if result[0]:
        return jsonify(message=f"details:{result[1]}"), 200
    else:
        return jsonify({"message": "sorry students not found"}), 400


@admin_bp.route("/delete/<int:student_id>", methods=["DELETE"])
def admin_delete(student_id):
    result = delete_student(student_id)
    if result[0]:
        return jsonify(message=f"deleted successfully {student_id}"), 200
    else:
        return jsonify({"message": "sorry student not found"}), 400


@admin_bp.route("/insert", methods=["POST"])
def admin_insert():
    data = request.get_json()
    name = data.get("name", "studentX")
    subject1 = data.get("subject1", 50)
    subject2 = data.get("subject2", 50)
    subject3 = data.get("subject3", 50)
    subject4 = data.get("subject4", 50)
    subject5 = data.get("subject5", 50)
    subject6 = data.get("subject6", 50)
    breakfast = data.get("breakfast", 0)
    lunch = data.get("lunch", 0)
    snacks = data.get("snacks", 0)
    dinner = data.get("dinner", 0)
    print(name, type(name))
    if name is None:
        name = "studentX"
    result = insert_student(
        name,
        subject1=subject1,
        subject2=subject2,
        subject3=subject3,
        subject4=subject4,
        subject5=subject5,
        subject6=subject6,
        breakfast=breakfast,
        lunch=lunch,
        snacks=snacks,
        dinner=dinner,
    )
    if result[0]:
        return jsonify(message=f"message is {result[1]}"), 200
    else:
        return jsonify({"message": "sorry student not found"}), 400
@admin_bp.route("/issue/insert", methods=["POST"])
def admin_insert_issue():
    data=request.get_json()
    if "id" not in data.keys():
        return jsonify({"message":"must mention student id"}),400
    result=add_issue(id=int(data['id']),issue=data['name'])
    if result[0]:
        return jsonify(message=f"message is {result[1]}"), 200
    else:
        return jsonify({"message": "sorry student_id not found"}), 400
    

@admin_bp.route("/update/<int:student_id>", methods=["PATCH"])
def admin_update(student_id):
    data = request.get_json()
    name = data.get("name", "studentX")
    subject1 = data.get("subject1", 50)
    subject2 = data.get("subject2", 50)
    subject3 = data.get("subject3", 50)
    subject4 = data.get("subject4", 50)
    subject5 = data.get("subject5", 50)
    subject6 = data.get("subject6", 50)
    breakfast = data.get("breakfast", 0)
    lunch = data.get("lunch", 0)
    snacks = data.get("snacks", 0)
    dinner = data.get("dinner", 0)
    print(name, type(name))
    print(student_id)
    result = update_student(
        student_id,
        name,
        subject1=subject1,
        subject2=subject2,
        subject3=subject3,
        subject4=subject4,
        subject5=subject5,
        subject6=subject6,
        breakfast=breakfast,
        lunch=lunch,
        snacks=snacks,
        dinner=dinner,
    )
    if result[0]:
        return jsonify(message=f"message is {result[1]}"), 200
    else:
        return jsonify({"message": "sorry student not found"}), 400
@admin_bp.route("/issues", methods=["GET"])  
def admin_all_issues():
    result=get_all_issues()
    if len(result)>0:
        return jsonify(message=f"result is {result}"),200
    else:
        return jsonify(message="empty set"), 400
@admin_bp.route("/issue/delete/<int:issue_id>", methods=["DELETE"])  
def admin_delete_issue(issue_id):
    result=delete_issue(issue_id)
    if result[0]:
        return jsonify(message="issue deleted successfully"),200
    else:
        return jsonify(message="issue not found to delete"), 400
@admin_bp.route("/create/menu", methods=["GET"])
def admin_create_menu():
    result = create_menu()
    if result[0]:
        return jsonify(message=f"details:{result[1]}"), 200
    else:
        return jsonify({"message": "sorry students not found"}), 400
@admin_bp.route("/delete/votes", methods=["DELETE"])
def admin_delete_votes():
    result = delete_votes()
    if result[0]:
        return jsonify(message=f"details:{result[1]}"), 200
    else:
        return jsonify({"message": "sorry students not found"}), 400


@jwt_required()
@student_bp.route("/", methods=["GET"])  
def student_route():
    current_user = get_jwt_identity()
    if current_user:  # Get username from token
        return (
            jsonify(message=f"Hello, {current_user}! Welcome to the student section."),
            200,
        )
    else:
        return jsonify(message="invalid credentials"), 400




@student_bp.route("/<int:student_id>", methods=["GET"])
@jwt_required()  # Protect with JWT
def get_stud(student_id):
    result = get_student(student_id)
    if result[0]:
        return (
            jsonify(
                message=f"Fetching student with ID: {student_id}"
                + f"details:{result[1]}"
            ),
            200,
        )
    else:
        return jsonify({"message": "sorry student not found"}), 400
@student_bp.route("/issue/<int:id>", methods=["GET"])
def issue_students(id):
    page, limit = 0, 10
    page = int(request.args["page"]) if "page" in request.args else 0
    limit = int(request.args["limit"]) if "limit" in request.args else 10
    result = get_student_issue(page=page, limit=limit,id=id)
    if result[0]:
        return jsonify(message=f"details:{result[1]}"), 200
    else:
        return jsonify({"message": "sorry students not found"}), 400
@student_bp.route("/menu", methods=["GET"])
def student_menu():
    result = get_menu()
    if result[0]:
        return jsonify(message=f"details:{result[1]}"), 200
    else:
        return jsonify({"message": "sorry students not found"}), 400

@student_bp.route("/cast_vote", methods=["POST"])
def cast_vote():  # sourcery skip: remove-redundant-if
    divisions=len(get_menu()[1])/4
    data=request.get_json()
    keys=data.keys()
    if "id" not in data.keys():
        return jsonify(message="student id is must"),400
    if "breakfast" not in keys or "lunch" not in keys or "snacks" not in keys or "dinner" not in keys:
        return jsonify(message="must vote for all meals"),400
    breakfast=int(data.get('breakfast'))
    if breakfast<1 or breakfast>divisions:
        return jsonify(message="select valid break fast"),400
    lunch=int(data.get('lunch'))
    if lunch<divisions+1 or lunch>2*divisions:
        return jsonify(message="select valid lunch"),400
    snacks=int(data.get('snacks'))
    if snacks<1+2*divisions or snacks>3*divisions:
        return jsonify(message="select valid snacks"),400
    dinner=int(data.get('dinner'))
    if dinner<1+3*divisions or dinner>4*divisions:
        return jsonify(message="select valid dinner"),400
    result=student_vote(student_id=data['id'],breakfast=breakfast,lunch=lunch,snacks=snacks,dinner=dinner)
    if result[0]:
        return jsonify(message='successful vote casted'),200
    else:
        return jsonify(message='vote not casted,try some other time/already casted try tomorrow' ),500
    
@student_bp.route("/mess_results", methods=["GET"])
def get_tomorrow_menu():
    result=finalize_menu()
    if result[0]:
        return jsonify(message=f'the menu of tomorrow is {result[1]}')
    else:
        return jsonify(message='not available right now,tey after some time')
@app.errorhandler(404)
def not_found(e):
    return jsonify({"error": "This route is invalid"}), 404


if __name__ == "__main__":
    app.register_blueprint(admin_bp, url_prefix="/admin")
    app.register_blueprint(student_bp, url_prefix="/student")

    app.run(debug=True)
