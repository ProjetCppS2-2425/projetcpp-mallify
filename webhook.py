from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/webhook', methods=['POST'])
def handle_call():
    data = request.json
    # Build the “verbs” array to tell Jambonz what to do
    response = [
        {
            "verb": "say",
            "text": "Hello! Connecting you now."
        },
        {
            "verb": "dial",
            "destination": {
                "type": "phone",
                "number": data.get("to")
            }
        },
        {
            "verb": "hangup"
        }
    ]
    return jsonify(response), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
